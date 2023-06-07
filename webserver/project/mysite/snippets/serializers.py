from datetime import timezone
from rest_framework import serializers
from snippets.models import Snippet, LANGUAGE_CHOICES, STYLE_CHOICES

class SnippetSerializer(serializers.ModelSerializer):
    owner = serializers.ReadOnlyField(source='owner.username')
    class Meta:
        model = Snippet
        # fields = '__all__'
        # exclude = ['highlighted']
    def create(self, validated_data):
        requested_user = self.context['request'].user
        now = timezone.now()
        snippets = Snippet.objects.create(
            owner=requested_user, created=now,
            **validated_data
        )
        return snippets