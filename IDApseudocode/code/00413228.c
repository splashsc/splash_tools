int *ctor_049()
{
  void **v0; // $a0
  int *result; // $v0

  v0 = off_66B584;
  result = &dword_66F220;
  off_66B584 = (void **)&dword_66F220;
  dword_66F220 = (int)&_httpd_cgi_all_fun;
  dword_66F224 = (int)v0;
  *v0 = &dword_66F220;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 66F220: using guessed type int dword_66F220;
// 66F224: using guessed type int dword_66F224;

