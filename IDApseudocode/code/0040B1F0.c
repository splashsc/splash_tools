int *ftext()
{
  int *result; // $v0

  result = &dword_667998;
  dword_6679B8 = (int)off_66B584;
  *off_66B584 = &dword_6679B4;
  off_66B584 = (void **)&dword_667998;
  dword_667998 = (int)&_httpd_cgi_all_fun;
  dword_66799C = (int)&dword_6679B4;
  dword_6679B4 = (int)&dword_667998;
  return result;
}
// 667998: using guessed type int dword_667998;
// 66799C: using guessed type int dword_66799C;
// 6679B4: using guessed type int dword_6679B4;
// 6679B8: using guessed type int dword_6679B8;
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;

