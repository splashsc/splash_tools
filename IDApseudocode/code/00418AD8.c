int *ctor_072()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_6746D0;
  off_66B584 = (void **)&dword_6746D0;
  dword_6746D0 = (int)&_httpd_cgi_all_fun;
  dword_6746D4 = (int)v0;
  *v0 = &dword_6746D0;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 6746D0: using guessed type int dword_6746D0;
// 6746D4: using guessed type int dword_6746D4;

