int __fastcall httpd_enable_write(int a1)
{
  int v1; // $s0
  int v2; // $v0
  size_t *v4; // $a1
  int result; // $v0
  int v6; // $v0
  _DWORD *v7; // $a1
  int v8; // $a2
  bool v9; // dc
  size_t *v10; // $a1
  ssize_t v11; // $v0
  int *v12; // $a1
  int v13; // $a2
  size_t v14; // $a2
  ssize_t v15; // $v0
  int v16; // $a2
  int v17; // $v0
  signed int v18; // $a2
  const void *v19; // $a1
  int v20; // $v0
  int v21; // $a1
  int v22; // $v0
  int v23; // $v0
  unsigned int v24; // $v0
  size_t v25; // $a1
  int v26; // $s2
  FILE *v27; // $a3
  int v28; // $a0
  size_t v29; // $a2
  const void *v30; // $s0
  signed int v31; // $v0
  size_t v32; // $a2
  int v33; // $v0
  unsigned int v34; // $a1
  unsigned int v35; // $a3
  int v36; // $a1
  int v37; // $a0
  int v38; // $v0
  FILE *v39; // $a3
  int v40; // $a0
  size_t v41; // $a2
  char *v42; // $s2
  signed int v43; // $v0
  size_t v44; // $a2
  int v45; // $v0
  int v46; // $a1
  int v47; // $v0
  int v48; // $s2
  int v49; // $v0
  int v50; // $a2
  unsigned int v51; // $v1
  int v52; // $a1
  int v53; // $v0
  int v54; // $s0
  int v55; // $v0
  int v56; // $a2
  unsigned int v57; // $v1
  int v58; // $a1
  int v59; // $v0

  v1 = a1 + 196608;
  v2 = *(_DWORD *)(a1 + 205412);
  if ( v2 != *(_DWORD *)(a1 + 205420) )
  {
    if ( v2 == *(_DWORD *)(a1 + 205424) )
    {
      v10 = *(size_t **)(a1 + 205444);
      if ( *v10 )
      {
        v11 = send(*(_DWORD *)(a1 + 205412), v10 + 1, *v10, 0);
        if ( v11 < 0 )
        {
          if ( *_errno_location() != 11 )
          {
            httpd_proxy_client_close(a1);
            return -1;
          }
        }
        else if ( v11 )
        {
          v12 = *(int **)(v1 + 8836);
          v13 = *v12 - v11;
          v9 = *v12 == v11;
          *v12 = v13;
          if ( v9 )
          {
            httpd_conn_epoll_read_proxy(a1);
            return 0;
          }
          memmove(v12 + 1, (char *)v12 + v11 + 4, v13);
          httpd_conn_epoll_write_proxy(a1);
        }
      }
      return 0;
    }
    v4 = *(size_t **)(a1 + 205440);
    if ( v4 )
    {
      result = 0;
      if ( !*v4 )
        return result;
      if ( *(_DWORD *)(a1 + 209984) )
        v6 = https_ssl_write(a1);
      else
        v6 = send(*(_DWORD *)(a1 + 205416), v4 + 1, *v4, 0);
      if ( v6 < 0 )
      {
        if ( *_errno_location() != 11 )
        {
          httpd_proxy_server_close(a1);
          return -1;
        }
      }
      else if ( v6 )
      {
        v7 = *(_DWORD **)(a1 + 205440);
        v8 = *v7 - v6;
        v9 = *v7 == v6;
        *v7 = v8;
        if ( v9 )
        {
          httpd_conn_epoll_read(a1);
        }
        else
        {
          memmove(v7 + 1, (char *)v7 + v6 + 4, v8);
          httpd_conn_epoll_write(a1);
        }
        return 0;
      }
      return 0;
    }
    v17 = *(unsigned __int8 *)(a1 + 42);
    if ( v17 == 2 )
    {
      if ( *(_DWORD *)(a1 + 205376) )
      {
        v24 = *(_DWORD *)(a1 + 205388);
        v25 = *(_DWORD *)(a1 + 205384);
        if ( __SPAIR64__(v24, v25) <= 0 )
          goto LABEL_38;
        v26 = a1 + 196608;
        v27 = *(FILE **)(a1 + 205592);
        if ( v27 )
        {
          if ( gl_hs_speed )
          {
            v54 = *(_DWORD *)(a1 + 209980);
            if ( v54 != jiffies_get() )
            {
              v55 = jiffies_get();
              v56 = *(_DWORD *)(v26 + 13364);
              v57 = v55 - *(_DWORD *)(v26 + 13372);
              *(_DWORD *)(v26 + 13372) = v55;
              v58 = 300 * v56;
              if ( v57 >= 0x12D )
                v57 = 300;
              v59 = v57 * v56 + *(_DWORD *)(a1 + 209976);
              if ( v58 >= v59 )
                *(_DWORD *)(a1 + 209976) = v59;
              else
                *(_DWORD *)(a1 + 209976) = v58;
            }
            if ( *(int *)(a1 + 209976) <= 0 )
              goto LABEL_32;
            v25 = *(_DWORD *)(a1 + 205384);
            v24 = *(_DWORD *)(a1 + 205388);
            v27 = *(FILE **)(a1 + 205592);
          }
          v28 = *(_DWORD *)(a1 + 209692);
          v29 = 4096 - v28;
          if ( __SPAIR64__(v24, v25) < 4096 - v28 )
            v29 = v25;
          v30 = (const void *)(a1 + 205596);
          v31 = fread((void *)(a1 + 205596 + v28), 1u, v29, v27);
          if ( v31 <= 0 )
          {
            fclose(*(FILE **)(a1 + 205592));
            *(_DWORD *)(a1 + 205592) = 0;
            *(_DWORD *)(a1 + 205384) = 0;
            *(_DWORD *)(a1 + 205388) = 0;
            httpd_release_caches();
            v32 = *(_DWORD *)(a1 + 209692);
          }
          else
          {
            v32 = v31 + *(_DWORD *)(a1 + 209692);
            v9 = gl_hs_speed == 0;
            *(_DWORD *)(a1 + 209692) = v32;
            if ( !v9 )
              *(_DWORD *)(a1 + 209976) -= v31;
          }
        }
        else
        {
          v32 = *(_DWORD *)(a1 + 209692);
          v30 = (const void *)(a1 + 205596);
        }
        if ( *(_DWORD *)(a1 + 209984) )
          v33 = https_ssl_write(a1);
        else
          v33 = send(*(_DWORD *)(a1 + 205416), v30, v32, 0);
        if ( v33 >= 0 )
        {
          v34 = *(_DWORD *)(a1 + 205384);
          v35 = v34 - v33;
          v36 = v34 < v33;
          v37 = *(_DWORD *)(a1 + 205388) - (v33 >> 31);
          *(_DWORD *)(a1 + 209692) -= v33;
          *(_DWORD *)(a1 + 205384) = v35;
          *(_DWORD *)(a1 + 205388) = v37 - v36;
          if ( v37 - v36 > 0 || v37 == v36 && v35 )
            goto LABEL_32;
          goto LABEL_38;
        }
      }
      else
      {
        v38 = *(_DWORD *)(a1 + 205380);
        if ( v38 <= 0 )
          goto LABEL_38;
        v39 = *(FILE **)(a1 + 205592);
        if ( v39 )
        {
          if ( gl_hs_speed )
          {
            v48 = *(_DWORD *)(a1 + 209980);
            if ( v48 != jiffies_get() )
            {
              v49 = jiffies_get();
              v50 = *(_DWORD *)(v1 + 13364);
              v51 = v49 - *(_DWORD *)(v1 + 13372);
              *(_DWORD *)(v1 + 13372) = v49;
              v52 = 300 * v50;
              if ( v51 >= 0x12D )
                v51 = 300;
              v53 = v51 * v50 + *(_DWORD *)(a1 + 209976);
              if ( v52 >= v53 )
                *(_DWORD *)(a1 + 209976) = v53;
              else
                *(_DWORD *)(a1 + 209976) = v52;
            }
            if ( *(int *)(a1 + 209976) <= 0 )
              goto LABEL_32;
            v38 = *(_DWORD *)(a1 + 205380);
            v39 = *(FILE **)(a1 + 205592);
          }
          v40 = *(_DWORD *)(a1 + 209692);
          v41 = 4096 - v40;
          v42 = (char *)(a1 + 205596);
          if ( v38 < 4096 - v40 )
            v41 = v38;
          v43 = fread(&v42[v40], 1u, v41, v39);
          if ( v43 <= 0 )
          {
            fclose(*(FILE **)(a1 + 205592));
            *(_DWORD *)(a1 + 205592) = 0;
            *(_DWORD *)(a1 + 205380) = 0;
            httpd_release_caches();
            v44 = *(_DWORD *)(a1 + 209692);
          }
          else
          {
            v44 = v43 + *(_DWORD *)(a1 + 209692);
            v9 = gl_hs_speed == 0;
            *(_DWORD *)(a1 + 209692) = v44;
            if ( !v9 )
              *(_DWORD *)(a1 + 209976) -= v43;
          }
        }
        else
        {
          v44 = *(_DWORD *)(a1 + 209692);
          v42 = (char *)(a1 + 205596);
        }
        if ( *(_DWORD *)(a1 + 209984) )
          v45 = https_ssl_write(a1);
        else
          v45 = send(*(_DWORD *)(a1 + 205416), v42, v44, 0);
        if ( v45 >= 0 )
        {
          v46 = *(_DWORD *)(a1 + 209692) - v45;
          v47 = *(_DWORD *)(a1 + 205380) - v45;
          *(_DWORD *)(a1 + 209692) = v46;
          *(_DWORD *)(a1 + 205380) = v47;
          if ( v47 > 0 )
            goto LABEL_32;
          goto LABEL_38;
        }
      }
    }
    else
    {
      v18 = *(_DWORD *)(a1 + 205380);
      if ( v18 <= 0 )
      {
LABEL_36:
        if ( v17 == 1 )
        {
          _mem_free(*(void **)(a1 + 205372));
          *(_DWORD *)(a1 + 205372) = 0;
          *(_BYTE *)(a1 + 42) = 0;
        }
LABEL_38:
        result = httpd_send_continue(a1);
        if ( result )
          return result;
LABEL_32:
        v23 = jiffies_get();
        mod_timer(a1 + 205540, v23 + 5000);
        return 0;
      }
      v19 = *(const void **)(a1 + 205368);
      if ( !v19 )
        goto LABEL_32;
      if ( *(_DWORD *)(a1 + 209984) )
        v20 = https_ssl_write(a1);
      else
        v20 = send(*(_DWORD *)(a1 + 205416), v19, v18, 0);
      if ( v20 >= 0 )
      {
        v21 = *(_DWORD *)(a1 + 205368) + v20;
        v22 = *(_DWORD *)(a1 + 205380) - v20;
        *(_DWORD *)(a1 + 205368) = v21;
        *(_DWORD *)(a1 + 205380) = v22;
        if ( v22 > 0 )
          goto LABEL_32;
        v17 = *(unsigned __int8 *)(a1 + 42);
        goto LABEL_36;
      }
    }
LABEL_61:
    httpd_conn_close((int *)a1);
    return -1;
  }
  v14 = *(_DWORD *)(a1 + 210028);
  if ( !v14 )
    return 0;
  v15 = write(*(_DWORD *)(a1 + 205412), *(const void **)(a1 + 210020), v14);
  if ( v15 < 0 )
  {
    if ( *_errno_location() == 11 )
      return 0;
    goto LABEL_61;
  }
  if ( !v15 )
    return 0;
  v16 = *(_DWORD *)(v1 + 13420) - v15;
  *(_DWORD *)(v1 + 13420) = v16;
  if ( v16 <= 0 )
    httpd_conn_epoll_read_pty(a1);
  else
    memmove(*(void **)(v1 + 13412), (void *)(*(_DWORD *)(v1 + 13412) + v15), v16);
  return 0;
}
// 67D0A0: using guessed type int gl_hs_speed;
// 6A81A4: using guessed type int __fastcall mod_timer(_DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);

