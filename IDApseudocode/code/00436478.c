int __fastcall httpd_proxy_cgi(int a1)
{
  int v1; // $s0
  int v2; // $v0
  int v5; // $v0
  uint16_t v6; // $a0
  int v7; // $v0
  struct sockaddr v8; // [sp+18h] [-10h] BYREF

  v1 = a1 + 196608;
  v2 = *(_DWORD *)(a1 + 205452);
  *(_DWORD *)&v8.sa_family = 0;
  *(_DWORD *)&v8.sa_data[2] = 0;
  *(_DWORD *)&v8.sa_data[6] = 0;
  *(_DWORD *)&v8.sa_data[10] = 0;
  if ( !v2 )
    return httpd_conn_close((int *)a1);
  if ( !*(_WORD *)(a1 + 205448) )
    return httpd_conn_close((int *)a1);
  if ( httpd_proxy_buf_init(a1) )
    return httpd_conn_close((int *)a1);
  memcpy((void *)(*(_DWORD *)(v1 + 8836) + 4), (void *)(a1 + 102964), *(_DWORD *)(v1 + 8756));
  v5 = *(_DWORD *)(v1 + 8844);
  v6 = *(_WORD *)(v1 + 8840);
  **(_DWORD **)(v1 + 8836) = *(_DWORD *)(v1 + 8756);
  v8.sa_family = 2;
  *(_DWORD *)&v8.sa_data[2] = v5;
  *(_WORD *)v8.sa_data = htons(v6);
  v7 = httpd_proxy_xconnect(&v8);
  *(_DWORD *)(v1 + 8816) = v7;
  if ( v7 < 0 )
    return httpd_conn_close((int *)a1);
  httpd_conn_epoll_add_proxy((_DWORD *)a1);
  httpd_conn_epoll_write_proxy(a1);
  setnonblocking(*(_DWORD *)(v1 + 8816));
  *(_DWORD *)(v1 + 8952) = httpd_proxy_do_rcv;
  *(_BYTE *)(a1 + 41) = 10;
  return 0;
}

