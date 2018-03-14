	var app =new Vue({		
		el:"#app",
		data:{
			id:"",
			name:"",
			lists:[{
				id:"3",
				name:"000"
			},
			{
				id:"4",
				name:"000"
			}],
			
		},
		methods:{
			fun1:function(){
//				alert("Success");
				var url="json/maininfo.json";
				self=this;
				$.get(url,function(data){	
				
					for(var i=0;i<data.data.length;i++){			
						if(self.id==data.data[i].id){								
//							self.lists[i].id=data.data[i].id;
//							self.lists[i].name=data.data[i].name;
							self.lists=data.data;
							console.log(data.data[i].name);
						}						
					}
					
				},"json");
			},

		},
	});
	var app1 =new Vue({		
		el:"#app1",
		data:{
			goods:[],
		},
		methods:{
			fun2:function(){
				var url="json/list.json";
				var self=this;
				
				$.get(url,function(data){	
					alert("Success");

					self.goods=data;
					console.log(data[0].id);

					
				},"json");
			},

		},
	});
	
