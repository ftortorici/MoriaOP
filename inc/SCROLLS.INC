        { Scrolls for the reading                               -RAK-   }
//[psect(misc2$code)]
procedure read;
	var
	i1: unsigned;
	i2,
	i3,
	i4,
	item_val,
//	mk1,
//	mklev,
//	thit,
//	tdam,
	y,
	x: integer;
	tmp: array [1 .. 5] of integer;
	out_val: AnsiString;
//	tmp_str,
//	mkstr: vtype;
	redraw, ident, first, flag: boolean;
	t: TMoriaInvenType;
	w: Treasure_Type;

	begin
	first     := true;
	reset_flag:= true;
//	if (inven_ctr > 0) then
//		begin
//		if (find_range([70, 71], i2, i3)) then
		if (py.flags.blind > 0) then
			msg_print('You can''t see to read the scroll.')
		else if (no_light) then
			msg_print('You have no light to read by.')
		else if (py.flags.confused > 0) then
			begin
//			msg_print('The Text Seems to Swim About the Page!');
			msg_print('You are too confused to read...');
			end
		else
			begin
//			redraw:= false;
//			if (get_item(item_val, 'Read Which Scroll?', redraw, i2, i3)) then
			if  GetItemFromInv(t, item_val, 'Read which scroll?',
					'You are not carrying any scrolls.', redraw, [70, 71]) then
				with newInventory[t, item_val] do
					begin
					if (redraw) then
						draw_cave;
					reset_flag:= False;
					i1        := flags;
//dengland			Identify by default
					ident     := True;
					while (i1 > 0) do
						begin
						i2:= bit_pos(i1);
						if (tval = 71) then
							i2:= i2 + 31;
						if (first) then
							if (not(i2 in [4, 25])) then
								begin
								msg_print('As you read the scroll it vanishes.');
								first:= false;
								end;

		{ Scrolls... }
						case (i2) of
							1:
								with newInventory[mitWornWielding, Ord(miwMainWeapon)] do
									begin
									if (tval > 0) then
										begin
										objdes(out_val, @(newInventory[mitWornWielding, Ord(miwMainWeapon)]), False);
										msg_print('Your ' + out_val + ' glows faintly!');
										if (enchant(tohit)) then
											begin
											flags:= ($7FFFFFFF and flags);
//											py_bonuses(blank_treasure, 0);
											ApplyBonuses(@blank_treasure, 0);
											end
										else
											msg_print('The enchantment fails...');
										end;
									ident:= true;
									end;
							2:
								with newInventory[mitWornWielding, Ord(miwMainWeapon)] do
									begin
									if (tval > 0) then
										begin
										objdes(out_val, @(newInventory[mitWornWielding, Ord(miwMainWeapon)]), false);
										msg_print('Your ' + out_val + ' glows faintly!');
										if (enchant(todam)) then
											begin
											flags:= ($7FFFFFFF and flags);
//											py_bonuses(blank_treasure, 0);
											ApplyBonuses(@blank_treasure, 0);
											end
										else
											msg_print('The enchantment fails...');
										end;
									ident:= true;
									end;
							3:
								begin
								i3:= 0;
								i4:= 0;
								if (newInventory[mitWornWielding, Ord(miwArmour)].tval > 0) then
									begin
									i3     := i3 + 1;
									tmp[i3]:= Ord(miwArmour);
									end;
								if (newInventory[mitWornWielding, Ord(miwBracers)].tval > 0) then
									begin
									i3     := i3 + 1;
									tmp[i3]:= Ord(miwBracers);
									end;
								if (newInventory[mitWornWielding, Ord(miwCloak)].tval > 0) then
									begin
									i3     := i3 + 1;
									tmp[i3]:= Ord(miwCloak);
									end;
								if (newInventory[mitWornWielding, Ord(miwGloves)].tval > 0) then
									begin
									i3     := i3 + 1;
									tmp[i3]:= Ord(miwGloves);
									end;
								if (newInventory[mitWornWielding, Ord(miwHelmet)].tval > 0) then
									begin
									i3     := i3 + 1;
									tmp[i3]:= Ord(miwHelmet);
									end;
								if (i3 > 0) then
									i4:= tmp[randint(i3)];
								if (($80000000 and newInventory[mitWornWielding, Ord(miwArmour)].flags) <> 0) then
									i4:= Ord(miwArmour)
								else if (($80000000 and newInventory[mitWornWielding, Ord(miwBracers)].flags) <> 0) then
									i4:= Ord(miwBracers)
								else if (($80000000 and newInventory[mitWornWielding, Ord(miwCloak)].flags) <> 0) then
									i4:= Ord(miwCloak)
								else if (($80000000 and newInventory[mitWornWielding, Ord(miwHelmet)].flags) <> 0) then
									i4:= Ord(miwHelmet)
								else if (($80000000 and newInventory[mitWornWielding, Ord(miwGloves)].flags) <> 0) then
									i4:= Ord(miwGloves);
								if (i4 > 0) then
									with newInventory[mitWornWielding, i4] do
										begin
										objdes(out_val, @(newInventory[mitWornWielding, i4]), false);
										msg_print('Your ' + out_val + ' glows faintly!');
										if (enchant(toac)) then
											begin
											flags:= ($7FFFFFFF and flags);
//											py_bonuses(blank_treasure, 0);
											ApplyBonuses(@blank_treasure, 0);
											end
										else
											msg_print('The enchantment fails...');
										end;
								ident:= true;
								end;
							4:
								begin
								identify(newInventory[t, item_val]);
								msg_print('This is an identify scroll');
								msg_print(' ');
								if (ident_spell) then
									first:= false;
								end;
							5:
								if (remove_curse) then
									begin
									msg_print('You feel as if someone is watching over you.');
									ident:= true;
									end;
							6:
								ident:= light_area(char_row, char_col);
							7:
								begin
								for i3:= 1 to randint(3) do
									begin
									y:= char_row;
									x:= char_col;
									summon_monster(y, x, false);
									end;
								ident:= true;
								end;
							8:
								begin
								teleport(10);
								ident:= true;
								end;
							9:
								begin
								teleport(100);
								ident:= true;
								end;
							10:
								begin
								msg_print('That scroll appeared to be blank.');
								ident:= true;
								end;
							11:
								begin
								msg_print('Your hands begin to glow.');
								py.flags.confuse_monster:= true;
								ident:= true;
								end;
							12:
								ident:= map_area;
							13:
								ident:= sleep_monsters2_3(char_row, char_col, 1);
							14:
								ident:= warding_glyph;
							15:
								ident:= detect_treasure;
							16:
								ident:= detect_object;
							17:
								ident:= detect_trap;
							18:
								ident:= detect_sdoor;
							19:
								begin
								msg_print('This is a mass genocide scroll.');
								msg_print(' ');
								ident:= mass_genocide;
								end;
							20:
								ident:= detect_invisible;
							21:
								begin
								ident:= aggravate_monster(20);
								msg_print('There is a high pitched humming noise');
								end;
							22:
								ident:= trap_creation;
							23:
								ident:= td_destroy;
							24:
								ident:= door_creation;
							25:
								begin
								identify(newInventory[t, item_val]);
								msg_print('This is a recharge scroll.');
								msg_print(' ');
								if (recharge(60)) then
									first:= false;
								end;
							26:
								begin
								msg_print('This is a genocide scroll.');
								msg_print(' ');
								ident:= genocide;
								end;
							27:
								ident:= unlight_area(char_row, char_col);
							28:
								ident:= protect_evil;
							29:
								ident:= create_food;
							30:
								ident:= dispell_creature($0008, 60);
							31:
								begin
								msg_print('That scroll appeared to be blank.');
								ident:= true;
								end;
							32:
								with newInventory[mitWornWielding, Ord(miwMainWeapon)] do
									begin
									if (tval > 0) then
										begin
										objdes(out_val, @(newInventory[mitWornWielding, Ord(miwMainWeapon)]), false);
										msg_print('Your ' + out_val + ' glows brightly!');
										flag  := false;
										for i3:= 1 to randint(2) do
											if (enchant(tohit)) then
												flag:= true;
										for i3:= 1 to randint(2) do
											if (enchant(todam)) then
												flag:= true;
										if (flag) then
											begin
											flags:= ($7FFFFFFF and flags);
//											py_bonuses(blank_treasure, 0);
											ApplyBonuses(@blank_treasure, 0);
											end
										else
											msg_print('The enchantment fails...');
										end;
									ident:= true;
									end;
							33:
								with newInventory[mitWornWielding, Ord(miwMainWeapon)] do
									begin
									if (tval > 0) then
										begin
										w:= newInventory[mitWornWielding, Ord(miwMainWeapon)];
										objdes(out_val, @(newInventory[mitWornWielding, Ord(miwMainWeapon)]), false);
										msg_print('Your ' + out_val + ' glows black, then fades.');
										tohit:= -randint(5) - randint(5);
										todam:= -randint(5) - randint(5);
										flags:= $80000000;
//										py_bonuses(inventory[inven_max], -1);
										ApplyBonuses(@w, -1);
										ident:= true;
										end;
									end;
							34:
								begin
								if (($80000000 and newInventory[mitWornWielding, Ord(miwArmour)].flags) <> 0) then
									i3:= Ord(miwArmour)
								else if (($80000000 and newInventory[mitWornWielding, Ord(miwBracers)].flags) <> 0) then
									i3:= Ord(miwBracers)
								else if (($80000000 and newInventory[mitWornWielding, Ord(miwCloak)].flags) <> 0) then
									i3:= Ord(miwCloak)
								else if (($80000000 and newInventory[mitWornWielding, Ord(miwHelmet)].flags) <> 0) then
									i3:= Ord(miwHelmet)
								else if (($80000000 and newInventory[mitWornWielding, Ord(miwGloves)].flags) <> 0) then
									i3:= Ord(miwGloves)
								else if (newInventory[mitWornWielding, Ord(miwArmour)].tval > 0) then
									i3:= Ord(miwArmour)
								else if (newInventory[mitWornWielding, Ord(miwBracers)].tval > 0) then
									i3:= Ord(miwBracers)
								else if (newInventory[mitWornWielding, Ord(miwHelmet)].tval > 0) then
									i3:= Ord(miwHelmet)
								else if (newInventory[mitWornWielding, Ord(miwGloves)].tval > 0) then
									i3:= Ord(miwGloves)
								else
									i3:= 0;
								if (i3 > 0) then
									with newInventory[mitWornWielding, i3] do
										begin
										objdes(out_val, @(newInventory[mitWornWielding, i3]), false);
										msg_print('Your ' + out_val + ' glows brightly!');
										flag  := false;
										for i3:= 1 to randint(2) + 1 do
											if (enchant(toac)) then
												flag:= true;
										if (flag) then
											begin
											flags:= ($7FFFFFFF and flags);
//											py_bonuses(blank_treasure, 0);
											ApplyBonuses(@blank_treasure, 0);
											end
										else
											msg_print('The enchantment fails...');
										end;
								ident:= true;
								end;
							35:
								begin
								if  ((newInventory[mitWornWielding, Ord(miwArmour)].tval > 0)
								and  (randint(4) = 1)) then
									i3:= Ord(miwArmour)
								else if ((newInventory[mitWornWielding, Ord(miwBracers)].tval > 0)
								and (randint(3) = 1)) then
									i3:= Ord(miwBracers)
								else if ((newInventory[mitWornWielding, Ord(miwCloak)].tval > 0)
								and (randint(3) = 1)) then
									i3:= Ord(miwCloak)
								else if ((newInventory[mitWornWielding, Ord(miwHelmet)].tval > 0)
								and (randint(3) = 1)) then
									i3:= Ord(miwHelmet)
								else if ((newInventory[mitWornWielding, Ord(miwGloves)].tval > 0)
								and (randint(3) = 1)) then
									i3:= Ord(miwGloves)
								else if (newInventory[mitWornWielding, Ord(miwArmour)].tval > 0) then
									i3:= Ord(miwArmour)
								else if (newInventory[mitWornWielding, Ord(miwBracers)].tval > 0) then
									i3:= Ord(miwBracers)
								else if (newInventory[mitWornWielding, Ord(miwCloak)].tval > 0) then
									i3:= Ord(miwCloak)
								else if (newInventory[mitWornWielding, Ord(miwHelmet)].tval > 0) then
									i3:= Ord(miwHelmet)
								else if (newInventory[mitWornWielding, Ord(miwGloves)].tval > 0) then
									i3:= Ord(miwGloves)
								else
									i3:= 0;
								if (i3 > 0) then
									with newInventory[mitWornWielding, i3] do
										begin
										w:= newInventory[mitWornWielding, i3];
										objdes(out_val, @(newInventory[mitWornWielding, i3]), false);
										msg_print('Your ' + out_val +
													' glows black, then fades.');
										flags:= $80000000;
										toac := -randint(5) - randint(5);
//										py_bonuses(inventory[inven_max], -1);
										ApplyBonuses(@w, -1);
										ident:= true;
										end;
								end;
							36:
								begin
								for i3:= 1 to randint(3) do
									begin
									y:= char_row;
									x:= char_col;
									summon_undead(y, x);
									end;
								ident:= true;
								end;
							37:
								ident:= bless(randint(12) + 6);
							38:
								ident:= bless(randint(24) + 12);
							39:
								ident:= bless(randint(48) + 24);
							40:
								begin
								ident:= true;
								py.flags.word_recall:= 25 + randint(30);
								msg_print('The air about you becomes charged...');
								end;
							41:
								ident:= destroy_area(char_row, char_col);
							42:
								;
							43:
								;
							44:
								;
							45:
								;
							46:
								;
							47:
								;
							48:
								;
							49:
								;
							50:
								;
							51:
								;
							52:
								;
							53:
								;
							54:
								;
							55:
								;
							56:
								;
							57:
								;
							58:
								;
							59:
								;
							60:
								;
							61:
								;
							62:
								;
							else
								;
							end;
		{ End of Scrolls... }
						end;
					if (not(reset_flag)) then
						begin
						if (ident) then
							identify(newInventory[t, item_val]);
						if (not(first)) then
							begin
							DescRemain(t, item_val);
							InvenDestroy(t, item_val);
							end;
						if (flags <> 0) then
							with py.misc do
								begin
								exp:= exp + round(level / lev);
								prt_experience;
								end;
						end;
					end
			else if (redraw) then
				draw_cave;
			end;
//		else
//			msg_print('You Are Not Carrying Any Scrolls.');
//		end
//	else
//		msg_print('But You Are Not Carrying Anything.');
	end;
