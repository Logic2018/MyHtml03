
		$(document).ready(function(){
			
			var a0=0;
			var a1=0;
			var a2=0;
			
			$("#input-but").click(function(){
					
				if(a0*a1*a2==1){
					alert("Success！");
				}
					
				else{
					alert("Please enter again！");
				}
										
			})
			

				$("input[name='uname']").blur(function(){
					var uname=$(this).val();
					if(uname==''||uname.length==0){
						$(this).next().text("用户名不能为空");
						a0=0;
					}else{
						$(this).next().text("");
						a0=1;
					}
				});
				$("input[name='password']").blur(function(){
					var len=$(this).val();	
					if(len.length<6){
						$(this).next().text("密码至少6位");
						a1=0;
					}else{
						$(this).next().text("");
						a1=1;
					}
				});
				
				$("input[name='email']").blur(function(){
					var email=$(this).val();
					var pattern=/^[a-zA-Z0-9_-]+@[a-zA-Z0-9_-]+(\.[a-zA-Z0-9_-]+)+$/;
					if(pattern.test(email)==false){
						$(this).next().text("邮箱格式错误");
						a2=0;
					}else{
						$(this).next().text("");
						a2=1;
					}
				});
				
		})
		

var app =new Vue({		
		el:"#app",
		data:{
			userdata:"",
			username:"",
			
		},
		methods:{
			fun1:function(){
//				alert("a");
				var url="/json/list.json";
				self=this;
				$.get(url,function(userdata){
					var k="0";
					for(var i=0;i<userdata.data.length;i++){
						if(self.username==userdata.data[i].username){
							k=self.username;
						}										
					}
					alert(k);
//					console.log(k);
					
				},"json");
			},
		},
	});




