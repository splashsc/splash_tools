int *ctor_102()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_67B130;
  off_66B584 = (void **)&dword_67B130;
  dword_67B130 = (int)&_httpd_cgi_all_fun;
  dword_67B134 = (int)v0;
  *v0 = &dword_67B130;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 67B130: using guessed type int dword_67B130;
// 67B134: using guessed type int dword_67B134;

