int __fastcall mrcl_ips_get_type(const char *a1)
{
  char *v1; // $s0
  const char *v3; // $a0

  v1 = (char *)&cl_ips_types;
  v3 = off_679864;
  if ( !off_679864 )
    return 0;
  while ( 1 )
  {
    v1 += 8;
    if ( !strcmp(v3, a1) )
      break;
    v3 = (const char *)*((_DWORD *)v1 + 1);
    if ( !v3 )
      return 0;
  }
  return *((_DWORD *)v1 - 2);
}
// 679864: using guessed type char *off_679864;

