int *ctor_095()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_67A5B0;
  off_66B584 = (void **)&dword_67A5B0;
  dword_67A5B0 = (int)&_httpd_cgi_all_fun;
  dword_67A5B4 = (int)v0;
  *v0 = &dword_67A5B0;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 67A5B0: using guessed type int dword_67A5B0;
// 67A5B4: using guessed type int dword_67A5B4;

