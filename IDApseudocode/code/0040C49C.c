int *ctor_007()
{
  int *result; // $v0

  result = &dword_66AA58;
  dword_66AA78 = (int)off_66B584;
  *off_66B584 = &dword_66AA74;
  off_66B584 = (void **)&dword_66AA58;
  dword_66AA58 = (int)&_httpd_cgi_all_fun;
  dword_66AA5C = (int)&dword_66AA74;
  dword_66AA74 = (int)&dword_66AA58;
  return result;
}
// 66AA58: using guessed type int dword_66AA58;
// 66AA5C: using guessed type int dword_66AA5C;
// 66AA74: using guessed type int dword_66AA74;
// 66AA78: using guessed type int dword_66AA78;
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;

