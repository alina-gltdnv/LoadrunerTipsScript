Step3()
{
	/*גגמהטל צטפנû */
	
INTENTER=atoi(lr_eval_string("{ENUMBER}"));

INTRETURN=atoi(lr_eval_string("{RNUMBER}"));

sum = INTENTER+INTRETURN;

lr_save_int(sum,"SUMPARAM");

web_reg_save_param("RQM", "LB=head_hd1\" value=\"", "RB=\" />", LAST );

web_reg_find("Text=Step 3", LAST);

lr_start_sub_transaction("3_Numbers", "Common");

	web_submit_data("LoadRunner_Correlation_Challenge_Exp.aspx_4",
	"Action={HostURL}/LoadRunner_Correlation_Challenge_Exp.aspx",
	"Method=POST",
	"TargetFrame=",
	"RecContentType=text/html",
	"Referer={HostURL}/LoadRunner_Correlation_Challenge_Exp.aspx",
	"Snapshot=t106.inf",
	"Mode=HTML",
	ITEMDATA,
	"Name=__EVENTTARGET", "Value={EVENTTARGET}", ENDITEM,
	"Name=__EVENTARGUMENT", "Value={EVENTARGUMENT}", ENDITEM,
	"Name=__VIEWSTATE", "Value={VIEWSTATE}", ENDITEM,
	"Name=__VIEWSTATEGENERATOR", "Value={VIEWSTATEGEN}", ENDITEM,
	"Name=__EVENTVALIDATION", "Value={EVENTVAL}", ENDITEM,
	"Name=ctl00$head$txtMagicNo", "Value={SUMPARAM}", ENDITEM,
	"Name=ctl00$head$btnStep2", "Value=Next", ENDITEM,
	LAST);

lr_end_sub_transaction("3_Numbers", LR_AUTO);

strcpy(fullpath, testURL);
strcat(fullpath, lr_eval_string("{RQM}"));
strcat(fullpath, lr_eval_string("&RND="));
strcat(fullpath, "0.52050452082067005");

strcpy(statusString,lr_eval_string("{RQM}"));

status = statusString[5];
ia = status - '0';
lr_save_int(ia,"OUTSTATUS");
web_add_header("Status",lr_eval_string("{OUTSTATUS}"));

lr_save_string(fullpath,"NEW_URL");


web_reg_find("Text=Try now it in Vegen",
LAST );

lr_start_sub_transaction("4_LastPage", "Common");

	web_url("LoadRunner_Correlation_Challenge_Exp.aspx_5",
	lr_eval_string("{NEW_URL}"),
	"TargetFrame=",
	"Resource=0",
	"RecContentType=text/html",
	"Referer={HostURL}/LoadRunner_Correlation_Challenge_Exp.aspx",
	"Snapshot=t107.inf",
	"Mode=HTML",
	LAST);
lr_end_sub_transaction("4_LastPage", LR_AUTO);
lr_end_transaction("Common", LR_AUTO);

return 0;
}