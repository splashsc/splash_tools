int *ctor_069()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_673C50;
  off_66B584 = (void **)&dword_673C50;
  dword_673C50 = (int)&_httpd_cgi_all_fun;
  dword_673C54 = (int)v0;
  *v0 = &dword_673C50;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 673C50: using guessed type int dword_673C50;
// 673C54: using guessed type int dword_673C54;

