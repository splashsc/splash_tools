int __fastcall httpd_file_ext_add(int a1)
{
  int *v2; // $v0
  int v3; // $s1
  int v4; // $s1
  int v5; // $v1
  int v6; // $a0
  _DWORD *v7; // $s1
  int result; // $v0

  v3 = get_name_hash(*(unsigned __int8 **)(a1 + 20));
  v2 = httpd_find_ext_file(*(const char **)(a1 + 20), v3);
  v4 = v3;
  if ( v2 )
    return -1;
  v5 = gl_vfile_ext_hash[v4];
  v6 = a1 + 8;
  *(_DWORD *)(a1 + 8) = v5;
  if ( v5 )
    *(_DWORD *)(v5 + 4) = v6;
  v7 = &gl_vfile_ext_hash[v4];
  *v7 = v6;
  result = 0;
  *(_DWORD *)(a1 + 12) = v7;
  return result;
}

