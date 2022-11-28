int *ctor_085()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_678220;
  off_66B584 = (void **)&dword_678220;
  dword_678220 = (int)&_httpd_cgi_all_fun;
  dword_678224 = (int)v0;
  *v0 = &dword_678220;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 678220: using guessed type int dword_678220;
// 678224: using guessed type int dword_678224;

