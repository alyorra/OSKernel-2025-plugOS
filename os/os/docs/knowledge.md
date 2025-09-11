前置学习

引导程序：
启动时，BIOS将磁盘第0个扇区（boot）加载到内存中 0x7c00
BIOS会先检查扇区的最后两个字节，1FE -> 0x55、1FF -> 0xaa
如果不是这两个值则不会成功启动

boot本身比较小，不能完成加载内核的工作，所以在磁盘上boot后面设置了loader
boot会读取磁盘，利用BIOS提供的磁盘操作的服务中断将loader加载到内存中 -> int $13
loader可以很大，能够完成初始化和加载操作系统内核的工作，这里将loader加载到0x8000

BIOS汇编打印字符
	; mov $0xe, %ah
	; mov $'L', %al
	; int $0x10

寄存器
EBX
EDX
EAX
ECX

内存检测
BIOS中断服务
返回内存中可用信息