int *ctor_027()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_668694;
  off_66B584 = (void **)&dword_668694;
  dword_668694 = (int)&_httpd_cgi_all_fun;
  dword_668698 = (int)v0;
  *v0 = &dword_668694;
  return result;
}
// 668694: using guessed type int dword_668694;
// 668698: using guessed type int dword_668698;
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;

