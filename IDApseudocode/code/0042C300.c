int httpd_mem_init()
{
  _DWORD *v0; // $v0
  _DWORD *v1; // $v1

  v0 = ll_httpd_conn_hash;
  v1 = &ll_mem_debug_hash;
  ll_mem_debug_list = (int)&ll_mem_debug_list;
  dword_67D064 = (int)&ll_mem_debug_list;
  ll_httpd_conn_used = (int)&ll_httpd_conn_used;
  dword_67D05C = (int)&ll_httpd_conn_used;
  ll_httpd_conn_pty = (int)&ll_httpd_conn_pty;
  dword_67D06C = (int)&ll_httpd_conn_pty;
  fbss = (int)&fbss;
  dword_67D054 = (int)&fbss;
  do
  {
    *v0++ = 0;
    *v1++ = 0;
  }
  while ( v0 != (_DWORD *)&ll_mem_debug_hash );
  return 0;
}
// 67D050: using guessed type int fbss;
// 67D054: using guessed type int dword_67D054;
// 67D058: using guessed type int ll_httpd_conn_used;
// 67D05C: using guessed type int dword_67D05C;
// 67D060: using guessed type int ll_mem_debug_list;
// 67D064: using guessed type int dword_67D064;
// 67D068: using guessed type int ll_httpd_conn_pty;
// 67D06C: using guessed type int dword_67D06C;

