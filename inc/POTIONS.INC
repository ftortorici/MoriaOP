{ Potions for the quaffing }
//[psect(misc2$code)]
procedure quaff;
	var
	i1: unsigned;
	i2,
//	i3,
	i4,
	i5,
	item_val, nhp: integer;
//	out_val: vtype;
	redraw,
	ident,
	tmp: boolean;
	t: TMoriaInvenType;

	begin
	reset_flag:= True;
//	if (inven_ctr > 0) then
//		begin
//		if (find_range([75, 76], i2, i3)) then
//			begin
//			redraw:= False;
//			if (get_item(item_val, 'Quaff Which Potion?', redraw, i2, i3)) then
			if  GetItemFromInv(t, item_val, 'Quaff which potion?',
					'You are not carrying any potions.', redraw, [75, 76]) then
				with newInventory[t, item_val] do
					begin
					if  redraw then
						draw_cave;
					reset_flag:= False;
					i1        := flags;
//dengland			Identify them by default
					ident     := True;
					while (i1 > 0) do
						begin
						i2:= bit_pos(i1);
						if (tval = 76) then
							i2:= i2 + 31;
{ Potions }
						case (i2) of
							1:
								with py.stat do
									begin
									cstr:= in_statp(cstr);
									if (cstr > str) then
										str:= cstr;
									msg_print('Wow!  What bulging muscles!');
									prt_strength;
									prt_max_weight;
									ident:= true;
									end;
							2:
								begin
								ident:= lose_str;
								prt_max_weight;
								end;
							3:
								with py.stat do
									begin
									cstr:= str;
									msg_print('You feel warm all over.');
									prt_strength;
									prt_max_weight;
									ident:= true;
									end;
							4:
								with py.stat do
									begin
									cint:= in_statp(cint);
									if (cint > py.stat.int) then
										py.stat.int:= cint;
									msg_print('Aren''t you brilliant!');
									prt_intelligence;
									ident:= true;
									end;
							5:
								begin
								msg_print('This potion tastes very dull.');
								ident:= lose_int;
								end;
							6:
								with py.stat do
									begin
									cint:= py.stat.int;
									msg_print('You have a warm feeling.');
									prt_intelligence;
									ident:= true;
									end;
							7:
								with py.stat do
									begin
									cwis:= in_statp(cwis);
									if (cwis > wis) then
										wis:= cwis;
									msg_print(
										'You suddenly have a profound thought!');
									prt_wisdom;
									ident:= true;
									end;
							8:
								ident:= lose_wis;
							9:
								with py.stat do
									if (cwis < wis) then
										begin
										cwis:= wis;
										msg_print(
											'You feel your wisdom returning.');
										prt_wisdom;
										ident:= true;
										end;
							10:
								with py.stat do
									begin
									cchr:= in_statp(cchr);
									if (cchr > chr) then
										chr:= cchr;
									msg_print('Gee, Ain''t you cute!');
									prt_charisma;
									ident:= true;
									end;
							11:
								ident:= lose_chr;
							12:
								with py.stat do
									if (cchr < chr) then
										begin
										cchr:= chr;
										msg_print(
											'You feel your looks returning.');
										prt_charisma;
										ident:= true;
										end;
							13:
								ident:= hp_player(damroll('2d7'), 'a potion.');
							14:
								ident:= hp_player(damroll('4d7'), 'a potion.');
							15:
								ident:= hp_player(damroll('6d7'), 'a potion.');
							16:
								ident:= hp_player(1000, 'a potion.');
							17:
								with py.misc do
									begin
									py.stat.ccon:= in_statp(py.stat.ccon);
									if (py.stat.ccon > py.stat.con) then
										py.stat.con:= py.stat.ccon;
									mhp            := mhp + 1;
									chp            := chp + mhp;
									msg_print('You feel tingly for a moment.');
									prt_mhp;
									prt_chp;
									prt_constitution;
									ident:= true;
									end;
							18:
								with py.misc do
									begin
									i5:= (exp div 2) + 10;
									if (i5 > 100000) then
										i5:= 100000;
									exp   := exp + i5;
									msg_print('you feel more experienced.');
									prt_experience;
									ident:= true;
									end;
							19:
								with py.flags do
									if (not(py.flags.free_act)) then
										begin
										msg_print('You fall asleep.');
										py.flags.paralysis:= py.flags.paralysis
												+ randint(4) + 4;
										ident:= true;
										end;
							20:
								with py.flags do
									begin
									msg_print(
										'You are covered by a veil of darkness.');
									blind:= blind + randint(100) + 100;
									ident:= true;
									end;
							21:
								with py.flags do
									begin
									msg_print(
										'Hey!  this is the good stuff!  * hick! *');
									confused:= confused + randint(20) + 12;
									ident   := true;
									end;
							22:
								with py.flags do
									begin
									msg_print('You feel very sick.');
									poisoned:= poisoned + randint(15) + 10;
									ident   := true;
									end;
							23:
								begin
								py.flags.fast:= py.flags.fast +
										randint(25) + 15;
								ident:= true;
								end;
							24:
								begin
								py.flags.slow:= py.flags.slow +
										randint(25) + 15;
								ident:= true;
								end;
							25:
								ident:= detect_monsters;
							26:
								with py.stat do
									begin
									cdex:= in_statp(cdex);
									if (cdex > dex) then
										dex:= cdex;
									msg_print('You feel more limber!');
									prt_dexterity;
									ident:= true;
									end;
							27:
								with py.stat do
									if (cdex < dex) then
										begin
										cdex:= dex;
										msg_print('You feel less clumsy.');
										prt_dexterity;
										ident:= true;
										end;
							28:
								with py.stat do
									if (ccon < con) then
										begin
										ccon:= con;
										msg_print(
											'You feel your health returning!');
										prt_constitution;
										ident:= true;
										end;
							29:
								begin
								tmp:= cure_blindness;
								ident:= ident or tmp;
								end;
							30:
								begin
								tmp:= cure_confusion;
								ident:= ident or tmp;
								end;
							31:
								begin
								tmp:= cure_poison;
								ident:= ident or tmp;
								end;
							32:
								with py.misc do
									with class_[pclass] do
										if (mspell) then
											begin
											ident:= learn_spell(redraw);
											if (redraw) then
												draw_cave;
											end
										else if (pspell) then
											ident:= learn_prayer;
							33:
								begin
								msg_print('You feel your memories fade...');
								msg_print('');
								i4:= (py.misc.exp div 5);
								lose_exp(randint(i4) + i4);
								ident:= true;
								end;
							34:
								with py.flags do
									begin
									poisoned:= 0;
									if (food > 150) then
										food := 150;
									paralysis:= 4;
									msg_print('The potion makes you vomit!');
									ident:= true;
									end;
							35:
								begin
								py.flags.invuln:= py.flags.invuln +
										randint(10) + 10;
								ident:= true;
								end;
							36:
								begin
								py.flags.hero:= py.flags.hero +
										randint(25) + 25;
								ident:= true;
								end;
							37:
								begin
								py.flags.shero:= py.flags.shero +
										randint(25) + 25;
								ident:= true;
								end;
							38:
								ident:= remove_fear;
							39:
								ident:= restore_level;
							40:
								with py.flags do
									resist_heat:= resist_heat +
											randint(10) + 10;
							41:
								with py.flags do
									resist_cold:= resist_cold +
											randint(10) + 10;
							42:
								detect_inv2(randint(12) + 12);
							43:
								ident:= slow_poison;
							44:
								ident:= cure_poison;
							45:
								with py.misc do
									if (cmana < mana) then
										begin
										cmana:= mana;
										ident:= true;
										msg_print(
											'Your feel your head clear...');
										prt_mana;
										end;
							46:
								with py.flags do
									begin
									tim_infra:= tim_infra + 100 + randint(100);
									ident    := true;
									msg_print('Your eyes begin to tingle.');
									end;
							47:
								with py.misc do
									begin
									msg_print('You have more stamina.');
									nhp:= randint(2) * get_hitdie;
									mhp:= mhp + nhp;
									chp:= chp + nhp;
									prt_mhp;
									prt_chp;
									end;
							48:
								with py.misc do
									begin
									msg_print('You feel more confident.');
									gain_mana(int_adj);
									gain_mana(int_adj);
									prt_mana;
									end;
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
{ End of Potions... } 	end;

					if (ident) then
						identify(newInventory[t, item_val]);

					if (flags <> 0) then
						begin
						with py.misc do
							exp:= exp + round(level / lev);
						prt_experience;
						end;

					add_food(p1);

					DescRemain(t, item_val);
					InvenDestroy(t, item_val);
					end
			else if (redraw) then
				draw_cave;
//			end
//		else
//			msg_print('You Are Not Carrying Any Potions.');
//		end
//	else
//		msg_print('But You Are Not Carrying Anything.');
	end;
