int *ctor_088()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_678F48;
  off_66B584 = (void **)&dword_678F48;
  dword_678F48 = (int)&_httpd_cgi_all_fun;
  dword_678F4C = (int)v0;
  *v0 = &dword_678F48;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 678F48: using guessed type int dword_678F48;
// 678F4C: using guessed type int dword_678F4C;

