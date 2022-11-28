int *ctor_066()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_672F40;
  off_66B584 = (void **)&dword_672F40;
  dword_672F40 = (int)&_httpd_cgi_all_fun;
  dword_672F44 = (int)v0;
  *v0 = &dword_672F40;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 672F40: using guessed type int dword_672F40;
// 672F44: using guessed type int dword_672F44;

