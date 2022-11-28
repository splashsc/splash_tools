int *ctor_079()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_6764E0;
  off_66B584 = (void **)&dword_6764E0;
  dword_6764E0 = (int)&_httpd_cgi_all_fun;
  dword_6764E4 = (int)v0;
  *v0 = &dword_6764E0;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 6764E0: using guessed type int dword_6764E0;
// 6764E4: using guessed type int dword_6764E4;

