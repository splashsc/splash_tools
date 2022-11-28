int *ctor_082()
{
  int *result; // $v0

  result = &dword_676E20;
  dword_676E40 = (int)off_66B584;
  *off_66B584 = &dword_676E3C;
  off_66B584 = (void **)&dword_676E20;
  dword_676E20 = (int)&_httpd_cgi_all_fun;
  dword_676E24 = (int)&dword_676E3C;
  dword_676E3C = (int)&dword_676E20;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 676E20: using guessed type int dword_676E20;
// 676E24: using guessed type int dword_676E24;
// 676E3C: using guessed type int dword_676E3C;
// 676E40: using guessed type int dword_676E40;

