int *ctor_005()
{
  int *result; // $v0

  result = &dword_66AAE4;
  dword_66AB04 = (int)off_66B584;
  *off_66B584 = &dword_66AB00;
  off_66B584 = (void **)&dword_66AAE4;
  dword_66AAE4 = (int)&_httpd_cgi_all_fun;
  dword_66AAE8 = (int)&dword_66AB00;
  dword_66AB00 = (int)&dword_66AAE4;
  return result;
}
// 66AAE4: using guessed type int dword_66AAE4;
// 66AAE8: using guessed type int dword_66AAE8;
// 66AB00: using guessed type int dword_66AB00;
// 66AB04: using guessed type int dword_66AB04;
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;

