 __asm__(".code16gcc");

 #include "loader.h"

 static boot_info_t boot_info;

 //打印信息
 static void show_msg (const char * msg) {
   char c;

   while ((c = *msg++) != '\0') {
      __asm__ __volatile__(
          "mov $0xe, %%ah\n\t"
	       "mov %[ch], %%al\n\t"
	       "int $0x10"::[ch]"r"(c)
      );
   }
 }
 
 //内存检测
 static void detect_memory (void) {
   unit32_t contID = 0;
   unit32_t signature, bytes;
   SMAP_entry_t smap_entry;

   show_msg("attempt to detect memory.");

   boot_info.ram_region_count = 0;
   for(int i = 0; i < BOOT_RAM_REGION_MAX; i++) {
      SMAP_entry_t * entry = &smap_entry;//定义一个指向smap_entry的指针

      __asm__ __volatile__("int $0x15"
            : "=a"(signature),"=c"(bytes),"=b"(contID)
            : "a"(0xE820),"b"(contID),"c"(24),"d"(0x534D4150),"D"(entry));

   if (signature != 0x534D4150) {
      show_msg("failed\r\n");
      return;
   }//调用失败

   if (bytes > 20 && (entry->ACPI & 0x0001) == 0) {
      continue;
   }

   if (entry->Type == 1) {
      boot_info.ram_region_cfg[boot_info.ram_region_count].start = entry->BaseL;
      boot_info.ram_region_cfg[boot_info.ram_region_count].size = entry->LengthL;
      boot_info.ram_region_count++;
   }

   if (contID == 0) {
      break;
   }}
   show_msg("ok.\r\n");
}

 void loader_entry (void) {
   show_msg ("......loading......\n\r");
   detect_memory();
   for (;;) {}
 }