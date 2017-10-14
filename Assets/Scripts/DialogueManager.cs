using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DialogueManager : MonoBehaviour {

	private Queue<string> sentences;

	public Text nameText;
	public Text dialogueText;
	public GameObject textField;

	// Use this for initialization
	void Start () {
		sentences = new Queue<string>();
		textField.SetActive(false);
	}
	
	public void StartDialogue(Dialogue dialogue)
	{
		textField.SetActive(true);

		nameText.text = dialogue.name;

		sentences.Clear();

		foreach(string sentence in dialogue.sentences)
		{
			sentences.Enqueue(sentence);
		}

		DisplayNextSentence();
	}

	public void DisplayNextSentence()
	{
		if(sentences.Count == 0)
		{
			EndDialogue();
			return;
		}

		string sentence = sentences.Dequeue();
		dialogueText.text = sentence;
		StopAllCoroutines();
		StartCoroutine(TypeSentence(sentence));
		//Debug.Log(sentence);
	}

	IEnumerator TypeSentence(string sentence)
	{
		dialogueText.text = "";
		foreach(char letter in sentence.ToCharArray())
		{
			dialogueText.text += letter;
			yield return null;
		}
	}

	void EndDialogue()
	{
		nameText.text = "";
		dialogueText.text = "";
		textField.SetActive(false);
	}

}
