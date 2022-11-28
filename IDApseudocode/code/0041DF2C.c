int *ctor_092()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_679CE8;
  off_66B584 = (void **)&dword_679CE8;
  dword_679CE8 = (int)&_httpd_cgi_all_fun;
  dword_679CEC = (int)v0;
  *v0 = &dword_679CE8;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 679CE8: using guessed type int dword_679CE8;
// 679CEC: using guessed type int dword_679CEC;

