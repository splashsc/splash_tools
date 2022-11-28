int __fastcall get_web_language_type(int a1)
{
  int result; // $v0

  if ( !*(_BYTE *)(a1 + 210103) )
    return *(unsigned __int8 *)(a1 + 210102);
  result = *(_DWORD *)(a1 + 32) & 0x10000000;
  if ( result )
    result = sub_4743FC(a1);
  return result;
}

