from rest_framework.viewsets import ModelViewSet
from .serializers import PostSerializer
from .models import Post
from rest_framework.views import APIView
from rest_framework.response import Response

class PostViewSet(ModelViewSet):
	queryset = Post.objects.all()
	serializer_class = PostSerializer

# @api_view(['GET'])
def public_post_list(request):
   qs=Post.objects.filter(is_public=True)
   serializer=PostSerializer(qs, many=True)
   return Response(serializer.data)
