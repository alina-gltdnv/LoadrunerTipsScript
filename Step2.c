Step2()
{
/* вводим город */
web_reg_save_param("VIEWSTATE", "LB=VIEWSTATE\" value=\"", "RB=\" />", LAST );
web_reg_save_param("VIEWSTATEGEN", "LB=VIEWSTATEGENERATOR\" value=\"", "RB=\" />", LAST );
web_reg_save_param("EVENTVAL", "LB=EVENTVALIDATION\" value=\"", "RB=\" />", LAST );
web_reg_save_param("EVENTTARGET", "LB=__EVENTTARGET\" id=\"", "RB=\" value=", LAST );
web_reg_save_param("EVENTARGUMENT", "LB=__EVENTARGUMENT\" id=\"", "RB=\" value=", LAST );
web_reg_save_param("ENUMBER", "LB=div id=\"head_divDDL\"><strong>\n\n\n\n\n", "RB=\n</div>", LAST );
web_reg_save_param("RNUMBER", "LB=return dd(&#39;", "RB=&#39;)", LAST );


web_reg_find("Text=Step 2", LAST);

lr_start_sub_transaction("2_City", "Common");

	web_submit_data("LoadRunner_Correlation_Challenge_Exp.aspx_3",
	"Action={HostURL}/LoadRunner_Correlation_Challenge_Exp.aspx",
	"Method=POST",
	"TargetFrame=",
	"RecContentType=text/html",
	"Referer={HostURL}/LoadRunner_Correlation_Challenge_Exp.aspx",
	"Snapshot=t105.inf",
	"Mode=HTML",
	ITEMDATA,
	"Name=__VIEWSTATE", "Value={VIEWSTATE}", ENDITEM,
	"Name=__VIEWSTATEGENERATOR", "Value={VIEWSTATEGEN}", ENDITEM,
	"Name=__EVENTVALIDATION", "Value={EVENTVAL}", ENDITEM,
	"Name={CNAME}", "Value=Alwar", ENDITEM, //Alwar
	"Name=ctl00$head$btnNext", "Value=Next", ENDITEM,
	LAST);

lr_end_sub_transaction("2_City", LR_AUTO);

return 0;
}