int __fastcall httpd_proxy_buf_init(int a1)
{
  int v1; // $s1
  void *v3; // $a0
  void *v4; // $a0
  int v5; // $s0
  int v6; // $v0
  int v7; // $v0
  int v9; // $a2

  v1 = a1 + 196608;
  v3 = *(void **)(a1 + 205440);
  if ( v3 )
  {
    _mem_free(v3);
    *(_DWORD *)(v1 + 8832) = 0;
  }
  v4 = *(void **)(a1 + 205444);
  if ( v4 )
  {
    _mem_free(v4);
    *(_DWORD *)(a1 + 205444) = 0;
  }
  _mem_malloc(102404, "httpd_proxy_buf_init", 302);
  v5 = a1 + 196608;
  *(_DWORD *)(v5 + 8832) = v6;
  if ( v6 )
  {
    _mem_malloc(102404, "httpd_proxy_buf_init", 308);
    *(_DWORD *)(v5 + 8836) = v7;
    if ( v7 )
      return 0;
    v9 = 311;
    if ( debug_level > 0 )
      goto LABEL_9;
  }
  else
  {
    v9 = 305;
    if ( debug_level > 0 )
    {
LABEL_9:
      printf("%s:%d malloc mem error\n", "httpd_proxy_buf_init", v9);
      return -1;
    }
  }
  return -1;
}
// 4363CC: variable 'v6' is possibly undefined
// 4363EC: variable 'v7' is possibly undefined
// 67D0BC: using guessed type int debug_level;

