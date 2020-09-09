int sum;
int INTENTER, INTRETURN;
char fullpath[1024],endURL[], * testURL = "URL={HostURL}/LoadRunner_Correlation_Challenge_Exp.aspx?RQM=";
char status;
char statusString[1024];
int ia;
Step1()
{
/*заходим на сайт*/
web_add_header("Upgrade-Insecure-Requests", "1");

web_reg_save_param("VIEWSTATE", "LB=VIEWSTATE\" value=\"", "RB=\" />", LAST );
web_reg_save_param("VIEWSTATEGEN", "LB=VIEWSTATEGENERATOR\" value=\"", "RB=\" />", LAST );
web_reg_save_param("EVENTVAL", "LB=EVENTVALIDATION\" value=\"", "RB=\" />", LAST );


web_reg_find("Text=The Challenges must be attempted in the order given", LAST);

lr_start_transaction("OpenPage");

	web_url("LoadRunner_Correlation_Challenge_Exp.aspx",
	"URL={HostURL}/LoadRunner_Correlation_Challenge_Exp.aspx",
	"TargetFrame=",
	"Resource=0",
	"RecContentType=text/html",
	"Referer={HostURL}/",
	"Snapshot=t129.inf",
	"Mode=HTML",
	LAST);

/*дебаг
lr_output_message(lr_eval_string("{VIEWSTATE}"));
lr_output_message(lr_eval_string("{VIEWSTATEGEN}"));
lr_output_message(lr_eval_string("{EVENTVAL}"));*/

lr_end_transaction("OpenPage", LR_AUTO);


/* нажимаем на старт */
lr_start_transaction("Common");


web_reg_save_param("VIEWSTATE", "LB=VIEWSTATE\" value=\"", "RB=\" />", LAST );
web_reg_save_param("VIEWSTATEGEN", "LB=VIEWSTATEGENERATOR\" value=\"", "RB=\" />", LAST );
web_reg_save_param("EVENTVAL", "LB=EVENTVALIDATION\" value=\"", "RB=\" />", LAST );
web_reg_save_param("CNAME", "LB=<input name=\"", "RB=\" type=\"text\"", LAST );

lr_start_sub_transaction("1_Start", "Common");

web_reg_find("Text=Step 1", LAST);

	web_submit_data("LoadRunner_Correlation_Challenge_Exp.aspx_2",
	"Action={HostURL}/LoadRunner_Correlation_Challenge_Exp.aspx",
	"Method=POST",
	"TargetFrame=",
	"RecContentType=text/html",
	"Referer={HostURL}/LoadRunner_Correlation_Challenge_Exp.aspx",
	"Snapshot=t104.inf",
	"Mode=HTML",
	ITEMDATA,
	"Name=__VIEWSTATE", "Value={VIEWSTATE}", ENDITEM,
	"Name=__VIEWSTATEGENERATOR", "Value={VIEWSTATEGEN}", ENDITEM,
	"Name=__EVENTVALIDATION", "Value={EVENTVAL}", ENDITEM,
	"Name=ctl00$head$btnStart", "Value=Start", ENDITEM,
	LAST);

lr_end_sub_transaction("1_Start", LR_AUTO);


return 0;
}
