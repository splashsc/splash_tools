int *ctor_053()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_670630;
  off_66B584 = (void **)&dword_670630;
  dword_670630 = (int)&_httpd_cgi_all_fun;
  dword_670634 = (int)v0;
  *v0 = &dword_670630;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 670630: using guessed type int dword_670630;
// 670634: using guessed type int dword_670634;

