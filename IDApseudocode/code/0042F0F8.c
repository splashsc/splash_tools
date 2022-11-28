int __fastcall httpd_conn_close(int *a1)
{
  int *v1; // $s1
  int v3; // $a0
  int v4; // $a0
  void *v5; // $a0
  FILE *v6; // $a0
  FILE *v7; // $a0
  void *v8; // $a0
  void *v9; // $a0
  void *v10; // $a0
  void *v11; // $a0
  void *v12; // $a0
  int *v13; // $v0
  int v14; // $v1
  int *v15; // $a0
  int v16; // $a1
  int v17; // $a2
  int *v18; // $a1
  int v19; // $a3

  v1 = a1 + 49152;
  v3 = a1[52496];
  if ( v3 )
  {
    SSL_shutdown(v3);
    SSL_free(v1[3344]);
    v1[3344] = 0;
  }
  if ( a1[51385] )
    del_timer(a1 + 51385);
  if ( a1[51354] != -1 )
  {
    httpd_conn_epoll_del((int)a1);
    close_socket(a1[51354]);
    a1[51354] = -1;
  }
  if ( a1[51355] != -1 )
  {
    httpd_conn_epoll_del_pty((int)a1);
    close_socket(a1[51355]);
    a1[51355] = -1;
  }
  if ( a1[51356] != -1 )
  {
    httpd_conn_epoll_del_proxy((int)a1);
    close_socket(a1[51356]);
    a1[51356] = -1;
  }
  if ( *((_BYTE *)a1 + 42) == 1 )
  {
    _mem_free((void *)a1[51343]);
    a1[51343] = 0;
  }
  v4 = a1[12];
  if ( v4 )
  {
    cJSON_Delete(v4);
    a1[12] = 0;
  }
  v5 = (void *)a1[51391];
  if ( v5 )
  {
    _mem_free(v5);
    a1[51391] = 0;
  }
  v6 = (FILE *)a1[51398];
  if ( v6 )
  {
    fclose(v6);
    a1[51398] = 0;
    a1[52423] = 0;
    httpd_release_caches();
  }
  v7 = (FILE *)a1[52424];
  if ( v7 )
  {
    fclose(v7);
    a1[52424] = 0;
    httpd_release_caches();
  }
  v8 = (void *)a1[52425];
  if ( v8 )
  {
    _mem_free(v8);
    a1[52425] = 0;
  }
  v9 = (void *)a1[52504];
  a1[52426] = 0;
  a1[52423] = 0;
  a1[51345] = 0;
  if ( v9 )
  {
    _mem_free(v9);
    a1[52504] = 0;
  }
  v10 = (void *)a1[52505];
  a1[52506] = 0;
  if ( v10 )
  {
    _mem_free(v10);
    a1[52505] = 0;
  }
  v11 = (void *)a1[51360];
  a1[52507] = 0;
  if ( v11 )
  {
    _mem_free(v11);
    a1[51360] = 0;
  }
  v12 = (void *)a1[51361];
  if ( v12 )
  {
    _mem_free(v12);
    a1[51361] = 0;
  }
  *((_BYTE *)a1 + 210100) = 0;
  a1[51363] = 0;
  *((_WORD *)a1 + 102724) = 0;
  _httpd_out_hash((int)a1);
  v13 = (int *)a1[1];
  v14 = *a1;
  *(_DWORD *)(v14 + 4) = v13;
  *v13 = v14;
  v15 = (int *)a1[3];
  v16 = a1[2];
  *a1 = 1048832;
  a1[1] = 2097664;
  *(_DWORD *)(v16 + 4) = v15;
  *v15 = v16;
  v17 = a1[4];
  v18 = (int *)a1[5];
  a1[2] = 1048832;
  a1[3] = 2097664;
  *(_DWORD *)(v17 + 4) = v18;
  *v18 = v17;
  a1[4] = 1048832;
  a1[5] = 2097664;
  _httpd_conn_m_free(a1);
  v19 = --ll_httpd_conn_dd_num;
  if ( debug_level > 0 )
    printf("%s:%d httpd_conn_close end conn all = %d\n", "httpd_conn_close", 642, v19);
  return 0;
}
// 67D0B0: using guessed type int ll_httpd_conn_dd_num;
// 67D0BC: using guessed type int debug_level;
// 6A8618: using guessed type int __fastcall SSL_shutdown(_DWORD);
// 6A8844: using guessed type int __fastcall cJSON_Delete(_DWORD);
// 6A88A0: using guessed type int __fastcall SSL_free(_DWORD);
// 6A896C: using guessed type int __fastcall del_timer(_DWORD);

