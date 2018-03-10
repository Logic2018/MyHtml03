		$("document").ready(function(){

				$("document").ready(function(){

				$("#input-but").click(function(){
					
					alert("登录成功");
					
				})
				
			})

	})
		
		
		var k1=0;
		var app1 =new Vue({		
		el:"#app1",
		data:{
			userdata:"",
			username:"",
			message:"",
			
		},
		methods:{
			fun1:function(){

				var url="json/list.json";
				self=this;
				$.get(url,function(userdata){	
				
					for(var i=0;i<userdata.data.length;i++){
//						console.log(self.username);
//						console.log(userdata.data[i].username);					
						if(self.username==userdata.data[i].username){								
							k1=i+1;
							console.log(k1);
						}						
					}
					if(k1!=0){
						self.message="";
					}else{
						self.message="用户名不存在！";
					}
					
				},"json");
			},

		},
	});
	;
	var app2 =new Vue({		
		el:"#app2",
		data:{
			userdata:"",
			password:"",
			message:"",
			
		},
		methods:{
			fun2:function(){
				var k2=0;
				var url="json/list.json";
				self=this;
				$.get(url,function(userdata){	
//					for(var i=0;i<userdata.data.length;i++){
						console.log(self.password);
						console.log(userdata.data[k1-1].password);					
						if(self.password==userdata.data[k1-1].password){								
							k2++;
						}						
//					}
					if(k2>0){
						self.message="";
					}else{
						self.message="密码错误！";
					}
					
				},"json");
			},

		},
	});
