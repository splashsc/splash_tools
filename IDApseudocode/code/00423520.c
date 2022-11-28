int __fastcall httpd_send_continue(int a1)
{
  _DWORD *v2; // $s0
  _DWORD *v3; // $v1
  int v4; // $v0
  int *v5; // $a1
  int v6; // $a0
  bool v7; // dc
  int v8; // $s7
  int v9; // $v0
  char *v10; // $s5
  int v11; // $v0
  int result; // $v0
  int v13; // $v0
  int v14; // $a2
  int v15; // $v0
  char v16[256]; // [sp+18h] [-108h] BYREF
  char *format; // [sp+118h] [-8h]

  format = "%s/%s";
LABEL_2:
  while ( 2 )
  {
    v2 = (_DWORD *)(a1 + 196608);
    v3 = *(_DWORD **)(a1 + 205392);
    if ( !v3 )
    {
LABEL_17:
      if ( *(int *)(a1 + 205380) <= 0 )
      {
        httpd_conn_send_finish(a1);
        return -1;
      }
      return 0;
    }
    while ( 1 )
    {
      v4 = v2[2198];
      if ( v4 >= v3[6] )
        goto LABEL_17;
      v5 = *(int **)(v3[8] + 4 * v4);
      v6 = *v5;
      v7 = *v5 == 1;
      v2[2198] = v4 + 1;
      if ( v7 )
      {
        *(_BYTE *)(a1 + 42) = 0;
        v13 = v5[2];
        v2[2190] = v5[1];
        v2[2193] = v13;
        v7 = httpd_send_data(a1) != 0;
        result = -1;
        if ( v7 )
          return result;
        if ( (int)v2[2193] > 0 )
          return 0;
        goto LABEL_2;
      }
      if ( v6 != 2 )
        break;
      ((void (__fastcall *)(int, int))v5[1])(a1, v5[3]);
      if ( (int)v2[2193] > 0 )
        return 0;
      v2 = (_DWORD *)(a1 + 196608);
      v3 = *(_DWORD **)(a1 + 205392);
      if ( !v3 )
        goto LABEL_17;
    }
    if ( v6 != 3 )
      goto LABEL_17;
    v8 = v3[5];
    sprintf(v16, format, "/etc_ro/web", v3[2]);
    _mem_malloc(v8 + 4, "httpd_send_continue", 4881);
    v10 = (char *)v9;
    if ( !v9 )
    {
      v14 = sprintf(v16, "malloc(%d);err!", v8 + 4);
      if ( v2[3344] )
        https_ssl_write(a1);
      else
        send(v2[2202], v16, v14, 0);
LABEL_22:
      httpd_conn_close((int *)a1);
      return -1;
    }
    v11 = do_file(v16, v9, v8);
    if ( v8 != v11 )
    {
      if ( v11 )
        v15 = sprintf(v10, "%s is modify !", v16);
      else
        v15 = sprintf(v10, "%s not exist !", v16);
      if ( v2[3344] )
        https_ssl_write(a1);
      else
        send(v2[2202], v10, v15, 0);
      _mem_free(v10);
      goto LABEL_22;
    }
    v2[2191] = v10;
    v2[2190] = v10;
    *(_BYTE *)(a1 + 42) = 1;
    v2[2193] = v8;
    result = httpd_send_data(a1);
    if ( result )
      return -1;
    if ( (int)v2[2193] <= 0 )
      continue;
    return result;
  }
}
// 423620: variable 'v9' is possibly undefined

