int __fastcall _httpd_out_hash(int a1)
{
  int v1; // $v0
  _DWORD *v2; // $v1
  int result; // $v0

  v1 = *(_DWORD *)(a1 + 24);
  v2 = *(_DWORD **)(a1 + 28);
  *v2 = v1;
  if ( v1 )
    *(_DWORD *)(v1 + 4) = v2;
  *(_DWORD *)(a1 + 24) = 1048832;
  result = 2097664;
  *(_DWORD *)(a1 + 28) = 2097664;
  return result;
}

