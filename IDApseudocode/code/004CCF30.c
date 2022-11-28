void __fastcall memcpy(void *dest, void *src, int n)
{
  MEMORY[0](dest, src, n);
  nvram_set_int();
}
// 4CCF40: using guessed type int nvram_set_int(void);

