int *ctor_038()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_66D964;
  off_66B584 = (void **)&dword_66D964;
  dword_66D964 = (int)&_httpd_cgi_all_fun;
  dword_66D968 = (int)v0;
  *v0 = &dword_66D964;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 66D964: using guessed type int dword_66D964;
// 66D968: using guessed type int dword_66D968;

