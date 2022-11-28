int *ctor_033()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_66C030;
  off_66B584 = (void **)&dword_66C030;
  dword_66C030 = (int)&_httpd_cgi_all_fun;
  dword_66C034 = (int)v0;
  *v0 = &dword_66C030;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 66C030: using guessed type int dword_66C030;
// 66C034: using guessed type int dword_66C034;

