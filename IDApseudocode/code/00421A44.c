int __fastcall httpd_send_referer(int a1)
{
  int v2; // $v0
  int result; // $v0
  char v4[2048]; // [sp+18h] [-800h] BYREF

  memset(v4, 0, sizeof(v4));
  v2 = sprintf(v4, (char *)re_httphead_str1, gl_referer);
  *(_BYTE *)(a1 + 41) = 2;
  *(_DWORD *)(a1 + 205392) = 0;
  result = httpd_send_data_alloc(a1, v4, v2);
  if ( !result )
  {
    result = *(_DWORD *)(a1 + 205380);
    if ( !result )
      result = httpd_conn_close((int *)a1);
  }
  return result;
}
// 666180: using guessed type void *re_httphead_str1;
// 666190: using guessed type char *gl_referer;

