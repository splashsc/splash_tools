int *ctor_077()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_675A60;
  off_66B584 = (void **)&dword_675A60;
  dword_675A60 = (int)&_httpd_cgi_all_fun;
  dword_675A64 = (int)v0;
  *v0 = &dword_675A60;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 675A60: using guessed type int dword_675A60;
// 675A64: using guessed type int dword_675A64;

