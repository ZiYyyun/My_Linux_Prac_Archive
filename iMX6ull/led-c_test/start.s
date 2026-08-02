.global _start
_start:
    /* 设置栈指针 SP，C语言需要栈 */
    ldr r0,=0x87800000
    add r0,r0,#0x4000
    mov sp,r0

    /* 跳转到C语言main函数 */
    bl main

loop:
    b loop   /* main函数返回后原地死循环 */