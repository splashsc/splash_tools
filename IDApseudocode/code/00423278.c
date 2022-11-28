int httpd_file_init()
{
  char *v0; // $v0
  _DWORD *v1; // $v0
  char *v2; // $v0
  int v3; // $s1
  void **v4; // $s2
  _DWORD *v5; // $s0
  int v6; // $v0
  int v7; // $v1
  _DWORD *v8; // $v0

  v0 = (char *)gl_vfile_ext_hash;
  do
  {
    *(_DWORD *)v0 = 0;
    v0 += 4;
  }
  while ( v0 != gl_httpd_adminpwd );
  v1 = gl_file_hash;
  do
    *v1++ = 0;
  while ( v1 != (_DWORD *)&gl_cgi_ext_hash );
  v2 = (char *)&gl_cgi_ext_hash;
  do
  {
    *(_DWORD *)v2 = 0;
    v2 += 4;
  }
  while ( gl_httpd_user != v2 );
  v3 = 0;
  v4 = &httpd_all_file;
  do
  {
    v5 = *v4;
    ++v3;
    v6 = get_name_hash(*((unsigned __int8 **)*v4 + 2));
    v7 = gl_file_hash[v6];
    v8 = &gl_file_hash[v6];
    *v5 = v7;
    if ( v7 )
      *(_DWORD *)(v7 + 4) = v5;
    *v8 = v5;
    ++v4;
    v5[1] = v8;
  }
  while ( v3 != 62 );
  return 0;
}
// 6679D0: using guessed type void *httpd_all_file;

