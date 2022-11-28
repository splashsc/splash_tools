int *ctor_080()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_6770A4;
  off_66B584 = (void **)&dword_6770A4;
  dword_6770A4 = (int)&_httpd_cgi_all_fun;
  dword_6770A8 = (int)v0;
  *v0 = &dword_6770A4;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 6770A4: using guessed type int dword_6770A4;
// 6770A8: using guessed type int dword_6770A8;

