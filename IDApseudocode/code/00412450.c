int *ctor_044()
{
  int *result; // $v0

  result = &dword_66E330;
  dword_66E36C = (int)off_66B584;
  *off_66B584 = &dword_66E368;
  dword_66E350 = (int)&dword_66E368;
  dword_66E368 = (int)&dword_66E34C;
  off_66B584 = (void **)&dword_66E330;
  dword_66E330 = (int)&_httpd_cgi_all_fun;
  dword_66E334 = (int)&dword_66E34C;
  dword_66E34C = (int)&dword_66E330;
  return result;
}
// 66B580: using guessed type void *_httpd_cgi_all_fun;
// 66B584: using guessed type void **off_66B584;
// 66E330: using guessed type int dword_66E330;
// 66E334: using guessed type int dword_66E334;
// 66E34C: using guessed type int dword_66E34C;
// 66E350: using guessed type int dword_66E350;
// 66E368: using guessed type int dword_66E368;
// 66E36C: using guessed type int dword_66E36C;

