_DWORD *_httpd_conn_m_alloc()
{
  _DWORD *v0; // $v0
  _DWORD *v1; // $s0
  _DWORD *v2; // $v1
  _DWORD *v3; // $v0

  if ( httpd_check_sys_freemem() )
    return 0;
  _mem_malloc(210104, "__httpd_conn_m_alloc", 128);
  v1 = v0;
  if ( !v0 )
    return 0;
  v2 = v0 + 2;
  v3 = v0 + 4;
  v1[2] = v2;
  v1[3] = v2;
  v1[4] = v3;
  v1[5] = v3;
  v1[6] = 0;
  v1[7] = 0;
  *v1 = v1;
  v1[1] = v1;
  init_timer(v1 + 51385);
  return v1;
}
// 42E7D4: variable 'v0' is possibly undefined
// 6A8368: using guessed type int __fastcall init_timer(_DWORD);
// 6A877C: using guessed type int httpd_check_sys_freemem(void);

