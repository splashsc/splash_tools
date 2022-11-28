int __fastcall sub_49F91C(int a1)
{
  bool v2; // dc
  int result; // $v0

  v2 = pppoe_bridge_check_token(a1) == 0;
  result = 0;
  if ( v2 )
    result = pppoe_br_user_asp(a1);
  return result;
}

