void __fastcall sub_433A60(uint32_t a1, uint32_t a2, void *a3, int a4)
{
  uint32_t v4; // $s1
  uint32_t *v8; // $v0
  uint32_t *v10; // $s0

  v4 = a4 + 12;
  _mem_malloc(a4 + 12, "httpd_unix_cgi_send_to_ac_server", 89);
  if ( v8 )
  {
    v10 = v8;
    *v8 = htonl(a1);
    v10[2] = a2;
    v10[1] = htonl(v4);
    if ( a3 )
    {
      if ( a4 )
        memcpy(v10 + 3, a3, a4);
    }
    httpd_unix_send_to_ac_server(v10, v4);
    _mem_free(v10);
  }
}
// 433AC4: variable 'v8' is possibly undefined

