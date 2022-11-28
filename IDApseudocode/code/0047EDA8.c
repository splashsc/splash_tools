int __fastcall sub_47EDA8(int a1)
{
  int v1; // $v0
  const char *v3; // $a1

  v1 = get_web_language_type(a1);
  if ( v1 == 1 )
  {
    v3 = "block_en.htm";
    return org_html(a1, (int)v3);
  }
  if ( v1 != 99 )
  {
    v3 = "block.htm";
    return org_html(a1, (int)v3);
  }
  return org_html(a1, (int)"block_ft.htm");
}

