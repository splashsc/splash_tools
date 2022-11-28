int *ctor_060()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_6725C0;
  off_66B584 = (void **)&dword_6725C0;
  dword_6725C0 = (int)&_httpd_cgi_all_fun;
  dword_6725C4 = (int)v0;
  *v0 = &dword_6725C0;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 6725C0: using guessed type int dword_6725C0;
// 6725C4: using guessed type int dword_6725C4;

