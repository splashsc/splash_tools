int *ctor_045()
{
  int *result; // $v0

  result = &dword_66F0CC;
  dword_66F0EC = (int)off_66B584;
  *off_66B584 = &dword_66F0E8;
  off_66B584 = (void **)&dword_66F0CC;
  dword_66F0CC = (int)&_httpd_cgi_all_fun;
  dword_66F0D0 = (int)&dword_66F0E8;
  dword_66F0E8 = (int)&dword_66F0CC;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 66F0CC: using guessed type int dword_66F0CC;
// 66F0D0: using guessed type int dword_66F0D0;
// 66F0E8: using guessed type int dword_66F0E8;
// 66F0EC: using guessed type int dword_66F0EC;

