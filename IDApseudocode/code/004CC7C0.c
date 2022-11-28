void __fastcall memmove(void *dest, void *src, int n)
{
  MEMORY[0](dest, src, n);
  del_timer();
}
// 4CC7D0: using guessed type int del_timer(void);

