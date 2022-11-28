int __fastcall httpd_conn_add(int a1, int a2, int a3)
{
  _DWORD *v6; // $s0
  int v7; // $a0
  int v8; // $a0
  int v9; // $s3
  int v10; // $s6
  int v11; // $s3
  int v12; // $s2
  int v13; // $a2
  int v14; // $v1
  int v15; // $v0
  int v17; // $s3
  int v18; // $a0
  int v19; // $a2
  int v20; // $a1
  int v21; // $a0
  int v22; // $v0
  int v23; // $v0
  int v24; // $v0
  int v25; // [sp+20h] [-10h] BYREF
  unsigned int v26; // [sp+24h] [-Ch]
  int v27; // [sp+28h] [-8h]
  int v28; // [sp+2Ch] [-4h]

  v6 = _httpd_conn_m_alloc();
  if ( !v6 )
    return -1;
  v7 = https_fd;
  v6[51355] = -1;
  v6[51356] = -1;
  v6[51354] = a1;
  v6[51352] = a3;
  *((_BYTE *)v6 + 210100) = 0;
  if ( a3 == v7 )
  {
    v25 = 0;
    v26 = 0;
    v27 = 0;
    v28 = 0;
    get_memory(&v25);
    if ( v26 < 0x1400000 || !https_ssl_ctx )
    {
      https_ssl_uninit(1);
      if ( https_ssl_init() )
      {
LABEL_25:
        _mem_free(v6);
        return -1;
      }
      https_accept_num = 0;
      v25 = 0;
      v26 = 0;
      v27 = 0;
      v28 = 0;
    }
    setnonblocking(v6[51354]);
    v21 = https_ssl_ctx;
    v6[52497] = 0;
    v22 = SSL_new(v21);
    v6[52496] = v22;
    SSL_set_fd(v22, a1);
    v23 = SSL_accept(v6[52496]);
    if ( v23 > 0 )
    {
      v24 = https_accept_num;
      v6[52497] = 1;
      https_accept_num = v24 + 1;
LABEL_19:
      v8 = v6[51354];
      goto LABEL_4;
    }
    if ( SSL_get_error(v6[52496], v23) == 2 )
      goto LABEL_19;
    SSL_shutdown(v6[52496]);
    SSL_free(v6[52496]);
    v6[52496] = 0;
    goto LABEL_25;
  }
  v8 = a1;
LABEL_4:
  setnonblocking(v8);
  memset(v6 + 51365, 0, 0x14u);
  v9 = *(_DWORD *)(a2 + 16);
  v10 = *(_DWORD *)(a2 + 8) | *(_DWORD *)(a2 + 12);
  if ( v9 ^ htonl(0xFFFFu) | v10 )
  {
    *((_BYTE *)v6 + 205460) = 1;
    v18 = *(_DWORD *)(a2 + 20);
    v19 = *(_DWORD *)(a2 + 12);
    v20 = *(_DWORD *)(a2 + 16);
    v6[51366] = *(_DWORD *)(a2 + 8);
    v6[51367] = v19;
    v6[51368] = v20;
    v6[51369] = v18;
    v6[51369] = v18;
  }
  else
  {
    v6[51366] = *(_DWORD *)(a2 + 20);
  }
  v11 = gl_hs_speed;
  *((_WORD *)v6 + 102740) = *(_WORD *)(a2 + 2);
  v12 = a1 & 0xFFF;
  *((_BYTE *)v6 + 40) = 0;
  *((_BYTE *)v6 + 41) = 0;
  v6[11] = 0;
  v6[12] = 0;
  v6[13] = 0;
  v6[51343] = 0;
  v6[51391] = 0;
  *((_BYTE *)v6 + 42) = 0;
  v6[51345] = 0;
  v6[51342] = 0;
  *((_BYTE *)v6 + 43) = 0;
  v6[51341] = 0;
  v6[51398] = 0;
  v6[52423] = 0;
  v6[52424] = 0;
  v6[52425] = 0;
  v6[52426] = 0;
  v6[52459] = 0;
  if ( v11 )
  {
    v6[52495] = jiffies_get();
    if ( v11 >= 100001 )
      v17 = (v11 / 1000) << 10;
    else
      v17 = (v11 << 10) / 1000;
    v6[52493] = v17;
    v6[52494] = v17;
  }
  httpd_conn_epoll_add((int)v6);
  _httpd_enter_hash(v12, (int)v6);
  v13 = ll_httpd_conn_used;
  v14 = ll_httpd_conn_dd_num + 1;
  v15 = ll_httpd_conn_all_num + 1;
  *(_DWORD *)(ll_httpd_conn_used + 4) = v6;
  *v6 = v13;
  v6[1] = &ll_httpd_conn_used;
  ll_httpd_conn_used = (int)v6;
  ll_httpd_conn_dd_num = v14;
  ll_httpd_conn_all_num = v15;
  v6[51389] = v6;
  v6[51387] = jiffies_get() + 10000;
  v6[51388] = httpd_keep_alive_timeout;
  add_timer(v6 + 51385);
  if ( debug_level > 0 )
    printf("%s:%d httpd_conn_add  conn all = %d fd =%d\n", "httpd_conn_add", 401, ll_httpd_conn_dd_num, v6[51354]);
  return 0;
}
// 67BD44: using guessed type int https_fd;
// 67D058: using guessed type int ll_httpd_conn_used;
// 67D0A0: using guessed type int gl_hs_speed;
// 67D0AC: using guessed type int ll_httpd_conn_all_num;
// 67D0B0: using guessed type int ll_httpd_conn_dd_num;
// 67D0BC: using guessed type int debug_level;
// 681500: using guessed type int https_accept_num;
// 681504: using guessed type int https_ssl_ctx;
// 6A838C: using guessed type int __fastcall add_timer(_DWORD);
// 6A8570: using guessed type int __fastcall SSL_accept(_DWORD);
// 6A85CC: using guessed type int __fastcall get_memory(_DWORD);
// 6A8618: using guessed type int __fastcall SSL_shutdown(_DWORD);
// 6A8658: using guessed type int __fastcall SSL_new(_DWORD);
// 6A8824: using guessed type int jiffies_get(void);
// 6A8860: using guessed type int __fastcall SSL_set_fd(_DWORD, _DWORD);
// 6A88A0: using guessed type int __fastcall SSL_free(_DWORD);
// 6A8990: using guessed type int __fastcall SSL_get_error(_DWORD, _DWORD);

